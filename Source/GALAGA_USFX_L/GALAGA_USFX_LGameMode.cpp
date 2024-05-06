// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_LGameMode.h"
#include "GALAGA_USFX_LPawn.h"
#include "NaveEnemigaEspia.h"
#include "EnemyLevel1.h"
#include "EnemyLevel2.h"
#include "EnemyLevel3.h"
#include "EnemyLevel4.h"
#include "EnemyLevel5.h"
#include "BattleSquadsReady.h" 
#include "DirectordeSquad.h"
#include "Kismet/GameplayStatics.h"//

AGALAGA_USFX_LGameMode::AGALAGA_USFX_LGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_LPawn::StaticClass();
	SpawnLocationInicial = FVector(303.530731f, -518.97937f, 214.727936f); // Ubicación inicial predeterminada
	SeparacionColumnas = 400.0f; // Separación predeterminada entre columnas
	SeparacionFilas = 500.0f; // Separación predeterminada entre filas

    // inicializando variables para el uso del nivel 1
    StartSpawnEnemyLevel1 = 0.f;//
    TopSpawnenemyLevel1 = 4.f;
    countEnemyL1 = 0;
    SpawnSquatLevel1 = 0.f;

    // inicializando variables para el uso del nivel 2
    StartSpawnEnemyLevel2 = 0.f;
    TopSpawnenemyLevel2 = 3.f;
    countEnemyL2 = 0;
    SpawnSquatLevel2 = 0.f;

    // inicializando variables para el uso del nivel 3
    StartSpawnEnemyLevel3 = 0.f;
    TopSpawnenemyLevel3 = 4.f;
    countEnemyL3 = 0;
    SpawnSquatLevel3 = 0.f;

    // inicializando variables para el uso del nivel 4
    StartSpawnEnemyLevel4 = 0.f;
    TopSpawnenemyLevel4 = 4.f;
    countEnemyL4 = 0;
    SpawnSquatLevel4 = 0.f;

    // inicializando variables para el uso del nivel 5
    StartSpawnEnemyLevel5 = 0.f;
    TopSpawnenemyLevel5 = 4.f;
    countEnemyL5 = 0;
    SpawnSquatLevel5 = 0.f;
}

void AGALAGA_USFX_LGameMode::BeginPlay()
{
    Super::BeginPlay();

    const FVector Location = FVector(0.f, 0.f, 240.0f);
    const FRotator Rotation = FRotator(0.f, 0.f, 0.f);
	// Creamos al jefe maestro enemigo
	DirectorSquadras = GetWorld()->SpawnActor<ADirectordeSquad>(ADirectordeSquad::StaticClass());//verifica si exicte la clase propia de unreal  
	// Sistema para la creacion de los escuadrones
	BattleSquads = GetWorld()->SpawnActor<ABattleSquadsReady>(ABattleSquadsReady::StaticClass()); 
	// Mandamos al jefe enemigo las escuadras listas para llamar  
	DirectorSquadras->setSquadBuilder(BattleSquads);
	//
	DirectorSquadras->ConstructSquads("");
	/*DirectorSquadras->ConstructSquads("SquadLevel2");
	DirectorSquadras->ConstructSquads("SquadLevel3");
	DirectorSquadras->ConstructSquads("SquadLevel4");
	DirectorSquadras->ConstructSquads("SquadLevel5");*/


    //const int32 NumeroDeColumnas = 2;
    //const int32 NumeroDeFilas = 5;

    //// Generar naves enemigas ANaveEnemigaEspia en una matriz de columnas y filas
    //for (int32 Columna = 0; Columna < NumeroDeColumnas; ++Columna)
    //{
    //    TArray<ANaveEnemigaEspia*> NavesEnColumna;
    //    for (int32 Fila = 0; Fila < NumeroDeFilas; ++Fila)
    //    {
    //        FVector SpawnLocation = SpawnLocationInicial + FVector(Columna * SeparacionColumnas, Fila * SeparacionFilas, 0.0f);
    //        FRotator SpawnRotation = FRotator(0.f, 0.f, 0.f);

    //        ANaveEnemigaEspia* NaveEnemigaEspia = GetWorld()->SpawnActor<ANaveEnemigaEspia>(SpawnLocation, SpawnRotation);

    //        if (NaveEnemigaEspia)
    //        {
    //            // Modificar la ubicación de la nave ANaveEnemigaEspia en función de la fila actual
    //            float OffsetY = Fila * SeparacionFilas;
    //            FVector NewSpawnLocation = SpawnLocationInicial + FVector(Columna * SeparacionColumnas, OffsetY, 0.0f);
    //            NaveEnemigaEspia->SetActorLocation(NewSpawnLocation);

    //            NavesEnColumna.Add(NaveEnemigaEspia);
    //        }
    //        else
    //        {
    //            NavesEnColumna.Add(nullptr);
    //        }
    //    }

    //    MatrizNaveEspia.Add(Columna, NavesEnColumna);
    //}

}


void AGALAGA_USFX_LGameMode::Tick(float DeltaTime)
{
	// nivel 1
		// Sistema para la aparicion de las naves enemigas de nivel 1
		StartSpawnEnemyLevel1 += DeltaTime;
		if (StartSpawnEnemyLevel1 >= TopSpawnenemyLevel1 && countEnemyL1 != 7)
		{
			StartSpawnEnemyLevel1 = 0.f;
			//float RandomSpawnY = FMath::RandRange(-370, 370);	// Un punto en el eje X
			//const FVector SpawnLocationEL1 = FVector(850, RandomSpawnY, 210.f);	// punto de creacion de la nave
			//const FRotator RotationEL1 = FRotator(0.f, 0.f, 0.f);	// rotacion de la nave

			//GetWorld()->SpawnActor<AEnemyLevel1>(SpawnLocationEL1, RotationEL1);
			//countEnemyL1 += 1;
		}

		// llamando a la creacion del primer escuadron
		SpawnSquatLevel1 += DeltaTime;
		if (SpawnSquatLevel1 >= 34.f && SpawnSquatLevel1 <= 36.f) {
			DirectorSquadras->ConstructSquads("SquadLevel1");
			SpawnSquatLevel1 += 10;
		/*	if (SoundAlarm != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, SoundAlarm, DirectorSquadras->GetActorLocation());*/
		}

	// nivel 2
	
		// Sistema para la aparicion de las naves enemigas de nivel 2
		StartSpawnEnemyLevel2 += DeltaTime;
		if (StartSpawnEnemyLevel2 >= TopSpawnenemyLevel2 && countEnemyL2 != 10)
		{
			StartSpawnEnemyLevel2 = 0.f;
			//float RandomSpawnY = FMath::RandRange(-370, 370);	// Un punto en el eje X
			//const FVector SpawnLocationEL2 = FVector(850, RandomSpawnY, 210.f);	// punto de creacion de la nave
			//const FRotator RotationEL2 = FRotator(0.f, 0.f, 0.f);	// rotacion de la nave

			//GetWorld()->SpawnActor<AEnemyLevel2>(SpawnLocationEL2, RotationEL2);
			//countEnemyL2 += 1;
		}

		// llamando a la creacion del segundo escuadron
		SpawnSquatLevel2 += DeltaTime;
		if (SpawnSquatLevel2 >= 40.f && SpawnSquatLevel2 <= 42.f) {
			DirectorSquadras->ConstructSquads("SquadLevel2");
			SpawnSquatLevel2 += 10;
			/*if (SoundAlarm != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, SoundAlarm, DirectorSquadras->GetActorLocation());*/
		}

	// nivel 3

		// Sistema para la aparicion de las naves enemigas de nivel 3
		StartSpawnEnemyLevel3 += DeltaTime;
		if (StartSpawnEnemyLevel3 >= TopSpawnenemyLevel3 && countEnemyL3 != 14)
		{
			StartSpawnEnemyLevel3 = 0.f;
			//float RandomSpawnY = FMath::RandRange(-370, 370);	// Un punto en el eje X
			//const FVector SpawnLocationEL3 = FVector(850, RandomSpawnY, 210.f);	// punto de creacion de la nave
			//const FRotator RotationEL3 = FRotator(0.f, 0.f, 0.f);	// rotacion de la nave

			//GetWorld()->SpawnActor<AEnemyLevel3>(SpawnLocationEL3, RotationEL3);
			//countEnemyL3 += 1;
		}

		// llamando a la creacion del tercer escuadron
		SpawnSquatLevel3 += DeltaTime;
		if (SpawnSquatLevel3 >= 65.f && SpawnSquatLevel3 <= 67.f) {
			DirectorSquadras->ConstructSquads("SquadLevel3");
			SpawnSquatLevel3 += 10;
	/*		if (SoundAlarm != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, SoundAlarm, DirectorSquadras->GetActorLocation());*/
		}


	// nivel 4
	
		// Sistema para la aparicion de las naves enemigas de nivel 4
		StartSpawnEnemyLevel4 += DeltaTime;
		if (StartSpawnEnemyLevel4 >= TopSpawnenemyLevel4 && countEnemyL4 != 15)
		{
			StartSpawnEnemyLevel4 = 0.f;
			//float RandomSpawnY = FMath::RandRange(-370, 370);	// Un punto en el eje X
			//const FVector SpawnLocationEL4 = FVector(850, RandomSpawnY, 210.f);	// punto de creacion de la nave
			//const FRotator RotationEL4 = FRotator(0.f, 0.f, 0.f);	// rotacion de la nave

			//GetWorld()->SpawnActor<AEnemyLevel4>(SpawnLocationEL4, RotationEL4);
			//countEnemyL4 += 1;
		}

		// llamando a la creacion del cuarto escuadron
		SpawnSquatLevel4 += DeltaTime;
		if (SpawnSquatLevel4 >= 75.f && SpawnSquatLevel4 <= 77.f) {
			DirectorSquadras->ConstructSquads("SquadLevel4");
			SpawnSquatLevel4 += 10;
		/*	if (SoundAlarm != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, SoundAlarm, DirectorSquadras->GetActorLocation());*/
		}

	// nivel 5

		// Sistema para la aparicion de las naves enemigas de nivel 5
		StartSpawnEnemyLevel5 += DeltaTime;
		if (StartSpawnEnemyLevel5 >= TopSpawnenemyLevel5 && countEnemyL5 != 20)
		{
			StartSpawnEnemyLevel5 = 0.f;
			//float RandomSpawnY = FMath::RandRange(-370, 370);	// Un punto en el eje X
			//const FVector SpawnLocationEL5 = FVector(850, RandomSpawnY, 210.f);	// punto de creacion de la nave
			//const FRotator RotationEL5 = FRotator(0.f, 0.f, 0.f);	// rotacion de la nave

			//GetWorld()->SpawnActor<AEnemyLevel5>(SpawnLocationEL5, RotationEL5);
			//bcountEnemyL5 += 1;
		}

		// llamando a la creacion del quinto escuadron
		SpawnSquatLevel5 += DeltaTime;
		if (SpawnSquatLevel5 >= 90.f && SpawnSquatLevel5 <= 92.f) {
			DirectorSquadras->ConstructSquads("SquadLevel5");
			SpawnSquatLevel5 += 10;
		/*	if (SoundAlarm != nullptr)
				UGameplayStatics::PlaySoundAtLocation(this, SoundAlarm, DirectorSquadras->GetActorLocation());*/
		}

}
