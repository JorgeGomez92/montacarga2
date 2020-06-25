// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadArduino.h"
#include <Runtime/Core/Public/Misc/Paths.h>
#include "HAL/PlatformFileManager.h"
#include "Misc/FileHelper.h"


FString UReadArduino::LoadFileToString(FString Filename)
{
	FString directory = FPaths::GameContentDir();
	FString result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	 
	if (file.CreateDirectory(*directory)) {
		FString myFile = directory + "/" + Filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}
	return result;
}

TArray<FString> UReadArduino::LoadFileToStringArray(FString Filename)
{
	FString directory = FPaths::GameContentDir();
	TArray<FString> result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory)) {
		FString myFile = directory + "/" + Filename;
		FFileHelper::LoadFileToStringArray(result, *myFile);
	}
	return result;
}
