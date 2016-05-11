// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Components/DestructibleComponent.h"
#include "KDestructibleBox.generated.h"

UCLASS(showCategories = ("Components|KDestructibleBox"), ComponentWrapperClass)
class FUTURECITY_API AKDestructibleBox : public AActor
{
	GENERATED_BODY()


private_subobject:
	UDestructibleComponent* _DestructibleComponent;
public:	
	// Sets default values for this actor's properties
	AKDestructibleBox();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UDestructibleComponent* Destructible() const;

};
