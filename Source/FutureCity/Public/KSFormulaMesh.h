// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "KSFormulaMesh.generated.h"

UCLASS()
class FUTURECITY_API AKSFormulaMesh : public AActor
{
	GENERATED_BODY()

private_subobject:
	TArray<FVector> *vertices;
	TArray<int32> *triangles;
	TArray<FVector>	*normals;
	TArray<FVector2D> *uvs;
	TArray<FColor> vertexColors;
	TArray<FProcMeshTangent> *tangents;

public:	
	// Sets default values for this actor's properties
	AKSFormulaMesh();

	float SuperFormula(float M, float N1, float N2, float N3, float Angle);

	UProceduralMeshComponent* _mesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
