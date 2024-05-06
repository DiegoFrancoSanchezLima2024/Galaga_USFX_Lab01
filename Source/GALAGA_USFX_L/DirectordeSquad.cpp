// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectordeSquad.h"
#include "SquadBuilder.h"

// Sets default values
ADirectordeSquad::ADirectordeSquad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADirectordeSquad::setSquadBuilder(AActor* Builder)
{
	//Castear el actor pasado y establecer el constructor
	SquadBuilder = Cast<ISquadBuilder>(Builder);
	if (!SquadBuilder) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("�Cast no v�lido! Consulte Registro de salida para obtener m�s detalles."));
		UE_LOG(LogTemp, Error, TEXT("setSquadBuilder():�El actor no es un SquadBuilder! �Est� seguro de que el actor implementa esa interfaz? "));
	}
}

void ADirectordeSquad::ConstructSquads(FString _SquadLevel)
{

        // Registrar si el constructor es NULL
        if (!SquadBuilder) {
            UE_LOG(LogTemp, Error, TEXT("ConstructSquads(): SquadBuilder es NULL, aseg�rese de que est� inicializado."));
            return;
        }

        // Mapeo de cadenas de nivel de escuadra a funciones de construcci�n
        TMap<FString, TFunction<void()>> SquadConstructionFunctions;
        SquadConstructionFunctions.Add("SquadLevel1", [this]() { SquadBuilder->buildSquadron1(); });
        SquadConstructionFunctions.Add("SquadLevel2", [this]() { SquadBuilder->buildSquadron2(); });
        SquadConstructionFunctions.Add("SquadLevel3", [this]() { SquadBuilder->buildSquadron3(); });
        SquadConstructionFunctions.Add("SquadLevel4", [this]() { SquadBuilder->buildSquadron4(); });
        SquadConstructionFunctions.Add("SquadLevel5", [this]() { SquadBuilder->buildSquadron5(); });

        // Verificar si existe una funci�n de construcci�n para el nivel dado
        if (SquadConstructionFunctions.Contains(_SquadLevel)) {
            // Llamar a la funci�n de construcci�n correspondiente
            SquadConstructionFunctions[_SquadLevel]();
        }
        else {
            UE_LOG(LogTemp, Warning, TEXT("ConstructSquads(): Nivel de escuadra no reconocido: %s"), *_SquadLevel);
        }

}



