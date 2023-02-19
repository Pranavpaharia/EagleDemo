// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestEagleGameMode.h"
#include "TestEagleCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"


ATestEagleGameMode::ATestEagleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATestEagleGameMode::RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot)
{
	//Find GroundFloor Player Start 
	TArray<AActor*> PlayerStartList;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), APlayerStart::StaticClass(), FName("GroundFloor"), PlayerStartList);

	if (PlayerStartList.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Ground Floor Player Start"));
		StartSpot = PlayerStartList[0];

	}

	

	//Spawn the Player Starts and Save them in a list
	int heightoffset = 700;
	
	for (int i = 0; i < NumberOfFloors; i++)
	{

		FVector Location(StartSpot->GetActorLocation().X, StartSpot->GetActorLocation().Y, StartSpot->GetActorLocation().Z + i * heightoffset);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		APlayerStart* nPlayerStart = GetWorld()->SpawnActor<APlayerStart>(Location, Rotation, SpawnInfo);
		nPlayerStart->PlayerStartTag = FName("Floor_" + FString::FromInt(i));
		FloorPlayerSpawnList.Add(nPlayerStart);
	}



	Super::RestartPlayerAtPlayerStart(NewPlayer, StartSpot);
}

void ATestEagleGameMode::ShiftCharacterUpstairs()
{

	if (!GetWorld() || 
		GetWorld()->GetFirstPlayerController() == nullptr || 
		GetWorld()->GetFirstPlayerController()->GetPawn() == nullptr
		)
		return;

	if (CurrentFloorIndex == NumberOfFloors - 1)
		CurrentFloorIndex = 0;
	else
		CurrentFloorIndex++;
	
	FVector nPos = FloorPlayerSpawnList[CurrentFloorIndex]->GetActorLocation();
	nPos = FVector(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X,
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y, nPos.Z);
	FRotator nRot = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();
	
	GetWorld()->GetFirstPlayerController()->GetPawn()->TeleportTo(nPos, nRot, false, true);
}

void ATestEagleGameMode::ShiftCharacterDownstairs()
{
	if (!GetWorld() ||
		GetWorld()->GetFirstPlayerController() == nullptr ||
		GetWorld()->GetFirstPlayerController()->GetPawn() == nullptr
		)
		return;

	if (CurrentFloorIndex == 0)
		CurrentFloorIndex = NumberOfFloors - 1;
	else
		CurrentFloorIndex--;

	FVector nPos = FloorPlayerSpawnList[CurrentFloorIndex]->GetActorLocation();
	nPos = FVector(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X,
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y, nPos.Z);
	FRotator nRot = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorRotation();

	GetWorld()->GetFirstPlayerController()->GetPawn()->TeleportTo(nPos, nRot, false, true);
}

FVector ATestEagleGameMode::GetNavLocationUpstairs()
{
	if (!GetWorld() ||
		GetWorld()->GetFirstPlayerController() == nullptr ||
		GetWorld()->GetFirstPlayerController()->GetPawn() == nullptr
		)
		return FVector::ZeroVector;

	if (CurrentFloorIndex == NumberOfFloors - 1)
		return GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	else
		CurrentFloorIndex++;


	FVector nPos = FloorPlayerSpawnList[CurrentFloorIndex]->GetActorLocation();
	
	nPos = FVector(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X,
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y, nPos.Z);
	

	return nPos;
}

FVector ATestEagleGameMode::GetNavLocationDownstairs()
{
	if (!GetWorld() ||
		GetWorld()->GetFirstPlayerController() == nullptr ||
		GetWorld()->GetFirstPlayerController()->GetPawn() == nullptr
		)
		return FVector::ZeroVector;


	if (CurrentFloorIndex == 0)
		return GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	else
		CurrentFloorIndex--;

	FVector nPos = FloorPlayerSpawnList[CurrentFloorIndex]->GetActorLocation();
	
	nPos = FVector(GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().X,
		GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Y, nPos.Z);


	return nPos;
}






void ATestEagleGameMode::BeginPlay()
{
	Super::BeginPlay();


	
}
