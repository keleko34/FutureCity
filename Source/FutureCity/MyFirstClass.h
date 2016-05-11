// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "KismetProceduralMeshLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyFirstClass.generated.h"

UCLASS()
class FUTURECITY_API AMyFirstClass : public AActor
{
	GENERATED_BODY()
	
public:

	/* Mesh of the street with all its lanes.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box")
	UProceduralMeshComponent* mesh;

	/* Material assigned to the building.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box")
	UMaterial* material;

	/* Builds a Box */
	UFUNCTION(BlueprintCallable, Category = "Box")
	void BuildBox(int sizeX, int sizeY, int sizeZ);

	// Sets default values for this actor's properties
	AMyFirstClass();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
