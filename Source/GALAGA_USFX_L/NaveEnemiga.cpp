// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemiga.h"
#include "Components/CapsuleComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystem.h"
#include "Components/ShapeComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "Components/BoxComponent.h"

// Sets default values
ANaveEnemiga::ANaveEnemiga()
{
    // Para que se vea mejor los Fotogramas del videojuego
    PrimaryActorTick.bCanEverTick = true;


    // Crea un componente de escena que sirve como raíz del actor
    Scena = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    RootComponent = Scena;

    // Creando la Malla para la nave Padre
    Nave_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Nave_Mesh"));
    // Establecer la malla de la nave como el componente raíz de la nave
    Nave_Mesh->SetupAttachment(RootComponent);

    // Crear un componente de colisión en forma de caja y establecerlo como el componente raíz de la nave
    Colision_Nave = CreateDefaultSubobject<UBoxComponent>(TEXT("Colision_Nave"));

    // Establecer la caja de colisión de la nave como el componente raíz de la nave
    Colision_Nave->SetupAttachment(RootComponent);

    // creando el campo de colision de la nave
    ShipEnemyCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision_Nave"));

    Velocidad = 100.0f;
    //Nombre_Nave = "";
}

// Called when the game starts or when spawned
void ANaveEnemiga::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANaveEnemiga::ComponenteDeDestruccion()
{
}

void ANaveEnemiga::Damage(float Damage)
{
}

// Called every frame
void ANaveEnemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

