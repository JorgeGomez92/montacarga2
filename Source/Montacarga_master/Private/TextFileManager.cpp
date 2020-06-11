// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

bool UTextFileManager::SaveArray(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverWriting = false)
{
    //Set complete file Path
    SaveDirectory += "\\";
    SaveDirectory += FileName;

    if(!AllowOverWriting)
    {
        if(FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
        {
            return false;
        }
    }
    int FinalInt= 0;
    FString FinalString= "";
    for(FString& Each : SaveText)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }

    return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}

