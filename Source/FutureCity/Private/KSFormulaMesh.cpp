// Fill out your copyright notice in the Description page of Project Settings.

#include "FutureCity.h"
#include "ProceduralMeshComponent.h"
#include "KSFormulaMesh.h"


// Sets default values
AKSFormulaMesh::AKSFormulaMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	vertices = new TArray<FVector>();
	triangles = new TArray<int32>();
	normals = new TArray<FVector>();
	uvs = new TArray<FVector2D>();
	tangents = new TArray<FProcMeshTangent>();
}

float AKSFormulaMesh::SuperFormula(float M, float N1, float N2, float N3, float Angle)
{
	float l_RetVal = 0.0;
	float l_Term1 = 0.0;
	float l_Term2 = 0.0;
	float l_A = 1.0;
	float l_B = 1.0;

	l_Term1 = (FMath::Cos((M * Angle / 4.0)) - l_A);
	l_Term1 = FMath::Abs(l_Term1);

	l_Term1 = FMath::Pow(l_Term1, N2);
	l_Term2 = (FMath::Sin(M * Angle / 4.0) / l_B);
	l_Term2 = FMath::Abs(l_Term2);
	l_Term2 = FMath::Pow(l_Term2, N3);
	l_RetVal = FMath::Pow((l_Term1 + l_Term2), (1.0 / N1));

	if(FMath::Abs(l_RetVal) == 0.0)
	{
		l_RetVal = 0.0;
	}
	else
	{
		l_RetVal = 1.0 / l_RetVal;
	}
	return l_RetVal;
}

// Called when the game starts or when spawned
void AKSFormulaMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKSFormulaMesh::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

