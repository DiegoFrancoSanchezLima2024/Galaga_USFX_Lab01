//// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFX_LGameMode.generated.h"

//class ANaveEnemigaEspia;
class ANaveEnemigaEspia;
class ABattleSquadsReady;
class ADirectordeSquad;

UCLASS(MinimalAPI)
class AGALAGA_USFX_LGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGALAGA_USFX_LGameMode();

private:
	ABattleSquadsReady* BattleSquads;     // Puntero a la clase ABattleSquadsReady
	ADirectordeSquad* DirectorSquadras;    // Puntero a la clase DirectordeSquad

protected:
	virtual void BeginPlay() override;

public:

	TMap<int32, TArray<ANaveEnemigaEspia*>> MatrizNaveEspia;

public:

	virtual void Tick(float DeltaTime) override;

	FVector SpawnLocationInicial;
	float SeparacionColumnas;
	float SeparacionFilas;

private:
	
	// propiedades para la creacion de enemigos nivel 1
	float StartSpawnEnemyLevel1;
	float TopSpawnenemyLevel1;
	int32 countEnemyL1;
	float SpawnSquatLevel1;

	// propiedades para la creacion de enemigos nivel 2
	float StartSpawnEnemyLevel2;
	float TopSpawnenemyLevel2;
	int32 countEnemyL2;
	float SpawnSquatLevel2;

	// propiedades para la creacion de enemigos nivel 3
	float StartSpawnEnemyLevel3;
	float TopSpawnenemyLevel3;
	int32 countEnemyL3;
	float SpawnSquatLevel3;

	// propiedades para la creacion de enemigos nivel 4
	float StartSpawnEnemyLevel4;
	float TopSpawnenemyLevel4;
	int32 countEnemyL4;
	float SpawnSquatLevel4;

	// propiedades para la creacion de enemigos nivel 5
	float StartSpawnEnemyLevel5;
	float TopSpawnenemyLevel5;
	int32 countEnemyL5;
	float SpawnSquatLevel5;

};



