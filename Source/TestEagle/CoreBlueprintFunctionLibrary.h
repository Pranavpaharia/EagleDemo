// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "CoreBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TESTEAGLE_API UCoreBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UCoreBlueprintFunctionLibrary();

	UFUNCTION(BlueprintCallable,Category = "Read/Write File")
	static FString LoadFileToString(FString Filename);

	UFUNCTION(BlueprintCallable,Category = "Read/Write File")
	static TArray<FString> LoadFileToStringArray(FString Filename);

	
};
