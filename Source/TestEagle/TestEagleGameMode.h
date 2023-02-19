// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TestEagle.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/PlayerStart.h"
#include "TestEagleGameMode.generated.h"

UCLASS(minimalapi)
class ATestEagleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestEagleGameMode();

	virtual void RestartPlayerAtPlayerStart(AController* NewPlayer, AActor* StartSpot) override;

	virtual void BeginPlay() override;

	//Cache Temprature Structure
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	FFloorTempratureStruct CacheTemp;

	// List of structures to hold Floor Temprature details
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<FFloorTempratureStruct> FloorTempList;

	//Check Parsing Flag
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	bool bParsing = false;

	//Player Start Spawn List 
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TArray<APlayerStart*> FloorPlayerSpawnList;

	//Total Number of Floors
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int NumberOfFloors = 10;

	//Current Floor Index
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int CurrentFloorIndex = 0;

	//Teleport Character to Above Floor
	UFUNCTION(BlueprintCallable)
	void ShiftCharacterUpstairs();


	//Teleport Character to Lower Floor
	UFUNCTION(BlueprintCallable)
	void ShiftCharacterDownstairs();


	//Find Above Floor location to Navigate 
	UFUNCTION(BlueprintCallable)
	FVector GetNavLocationUpstairs();

	//Find Below Floor location to Navigate
	UFUNCTION(BlueprintCallable)
	FVector GetNavLocationDownstairs();

	

	

};



