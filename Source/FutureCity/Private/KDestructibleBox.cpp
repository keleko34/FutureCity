// Fill out your copyright notice in the Description page of Project Settings.

#include "FutureCity.h"
#include "KDestructibleBox.h"
#include "Components/DestructibleComponent.h"


// Sets default values
AKDestructibleBox::AKDestructibleBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_DestructibleComponent = CreateDefaultSubobject<UDestructibleComponent>(TEXT("DestructibleComponent0"));
	RootComponent = _DestructibleComponent;
}


UDestructibleComponent* AKDestructibleBox::Destructible() const { return _DestructibleComponent; };

// Called when the game starts or when spawned
void AKDestructibleBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKDestructibleBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

