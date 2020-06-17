// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextFileManager.generated.h"

/**
 * 
 */
UCLASS()
class MONTACARGA_MASTER_API UTextFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords="Save"))
	static bool SaveArray(FString SaveDirectory, FString FileName,TArray<FString> Usuario ,  TArray<FString> TiempoF, TArray<FString> TiempoM, TArray<FString> TiempoD, TArray<FString> CajasF, TArray<FString> CajasM, TArray<FString> CajasD, TArray<FString> ScoreF, TArray<FString> ScoreM, TArray<FString> ScoreD, bool AllowOverWriting);
	
};
