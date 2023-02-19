// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TestEagle.generated.h"


// Floor Temprature Structure 
USTRUCT(BlueprintType)
struct FFloorTempratureStruct
{
	GENERATED_BODY()

public:

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 FloorNumber = 0;

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxTemp = 0;

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinTemp = 0;


	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float CurrentTemp = 0;
};


//Navigation Mode Enums
UENUM(BlueprintType)
enum class EEagleMovementMode : uint8
{
	
	OnTeleportStyle,

	
	OnAutoWalk
};