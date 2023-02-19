// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreBlueprintFunctionLibrary.h"
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/PlatformFileManager.h"

UCoreBlueprintFunctionLibrary::UCoreBlueprintFunctionLibrary()
{

}

FString UCoreBlueprintFunctionLibrary::LoadFileToString(FString Filename)
{
	FString dir = FPaths::GameSourceDir();
	FString resultString;

	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();


	if (file.CreateDirectory(*dir))
	{
		FString myFile = dir + "/" + Filename;
		FFileHelper::LoadFileToString(resultString, *myFile);
	}

	return resultString;

}

TArray<FString> UCoreBlueprintFunctionLibrary::LoadFileToStringArray(FString Filename)
{
	FString dir = FPaths::ProjectContentDir();
	TArray<FString> resultStringArray;

	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*dir))
	{
		FString myFile = dir + "/" + Filename;
		FFileHelper::LoadFileToStringArray(resultStringArray, *myFile);
	}

	return resultStringArray;

}