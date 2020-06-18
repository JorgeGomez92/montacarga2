// Fill out your copyright notice in the Description page of Project Settings.


#include "TextFileManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFileManager.h"

bool UTextFileManager::SaveArray(FString SaveDirectory, FString FileName, TArray<FString> Usuario,  TArray<FString> TiempoF, TArray<FString> TiempoM, TArray<FString> TiempoD, TArray<FString> CajasF, TArray<FString> CajasM, TArray<FString> CajasD, TArray<FString> ScoreF, TArray<FString> ScoreM, TArray<FString> ScoreD, bool AllowOverWriting = false)
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
    
    FString FinalString = "";
    FString Delimiter = ", ";
    FString DatosTiempo1 = "";
    FString DatosTiempo2 = "";
    FString DatosTiempo3 = "";
    FString DatosCaja1 = "";
    FString DatosCaja2 = "";
    FString DatosCaja3 = "";
    FString DatosScore1 = "";
    FString DatosScore2 = "";
    FString DatosScore3 = "";

    
    FString Nombre = "Nombre";
    Nombre += Delimiter;
    FString Tiempo1 = "Tiempo Facil";
    Tiempo1 += Delimiter;
    FString Tiempo2 = "Tiempo Intermedio";
    Tiempo2 += Delimiter;
    FString Tiempo3 = "Tiempo Dificil";
    Tiempo3 += Delimiter;
    FString Cajas1 = "Cajas Facil";
    Cajas1 += Delimiter;
    FString Cajas2 = "Cajas Intermedio";
    Cajas2 += Delimiter;
    FString Cajas3 = "Cajas Dificil";
    Cajas3 += Delimiter;
    FString Score1 = "Score Facil";
    Score1 += Delimiter;
    FString Score2 = "Score Intermedio";
    Score2 += Delimiter;
    FString Score3 = "Score Dificil";
    Score3 += Delimiter;


 
   
    FString UserName= "";

    for(FString& Each : Usuario)
    {           
        UserName += Each;        
        UserName += LINE_TERMINATOR;
    }
    
    for(FString& Each : TiempoF)
    {           
        DatosTiempo1 += Each;        
        DatosTiempo1 += Delimiter;
    }
    DatosTiempo1 += LINE_TERMINATOR;

    for(FString& Each : TiempoM)
    {           
        DatosTiempo2 += Each;        
        DatosTiempo2 += Delimiter;
    }
    DatosTiempo2 += LINE_TERMINATOR;
    
    for(FString& Each : TiempoD)
    {           
        DatosTiempo3 += Each;        
        DatosTiempo3 += Delimiter;
    }
    DatosTiempo3 += LINE_TERMINATOR;

    for(FString& Each : CajasF)
    {           
        DatosCaja1 += Each;        
         DatosCaja1 += Delimiter;
    }
    DatosCaja1 += LINE_TERMINATOR;

    for(FString& Each : CajasM)
    {           
        DatosCaja2 += Each;        
         DatosCaja2 += Delimiter;
    }
    DatosCaja2 += LINE_TERMINATOR;

    for(FString& Each : CajasD)
    {           
        DatosCaja3 += Each;        
         DatosCaja3 += Delimiter;
    }
    DatosCaja3 += LINE_TERMINATOR;
    
    for(FString& Each : ScoreF)
    {           
        DatosScore1 += Each;        
        DatosScore1 += Delimiter;
    }
    DatosScore1 += LINE_TERMINATOR;
    
    for(FString& Each : ScoreM)
    {           
        DatosScore2 += Each;        
        DatosScore2 += Delimiter;
    }
    DatosScore2 += LINE_TERMINATOR;

    for(FString& Each : ScoreD)
    {           
        DatosScore3 += Each;        
        DatosScore3 += Delimiter;
    }
    DatosScore3 += LINE_TERMINATOR;


    return FFileHelper::SaveStringToFile(Nombre + UserName +  Tiempo1 + DatosTiempo1 + Cajas1 + DatosCaja1 +  Score1 + DatosScore1 + Tiempo2 + DatosTiempo2 + Cajas2 + DatosCaja2 + Score2 + DatosScore2 + Tiempo3 + DatosTiempo3   + Cajas3 + DatosCaja3  +  Score3 + DatosScore3,   *SaveDirectory);
}

