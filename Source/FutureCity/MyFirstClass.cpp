// Fill out your copyright notice in the Description page of Project Settings.

#include "FutureCity.h"
#include "KismetProceduralMeshLibrary.h"
//#include "ProceduralMeshComponent.h"
#include "MyFirstClass.h"


// Sets default values
AMyFirstClass::AMyFirstClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	#ifdef UE_BUILD_DEBUG
		UE_LOG(LogTemp, Warning, TEXT("Constructing a procedural mesh actor."));
	#endif


		UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));

	/*
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;

	UProceduralMeshComponent* mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	*/
	/**
	*	Create/replace a section for this procedural mesh component.
	*	@param	SectionIndex		Index of the section to create or replace.
	*	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	*	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	*	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	*	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	*	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	*	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	*/
	//UFUNCTION(BlueprintCallable, Category = "Components|ProceduralMesh", meta = (AutoCreateRefTerm = "Normals,UV0,VertexColors,Tangents"))
	//	void CreateMeshSection(int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals,
	// const TArray<FVector2D>& UV0, const TArray<FColor>& VertexColors, const TArray<FProcMeshTangent>& Tangents, bool bCreateCollision);
	
	FVector* radius = new FVector(50,50,50);

	TArray<FVector> *vertices = new TArray<FVector>();
	TArray<int32> *triangles = new TArray<int32>();
	TArray<FVector> *normals = new TArray<FVector>();
	TArray<FVector2D> *uvs = new TArray<FVector2D>();
	TArray<FColor> vertexColors;
	TArray<FProcMeshTangent>* tangents = new TArray<FProcMeshTangent>();

	UKismetProceduralMeshLibrary::GenerateBoxMesh(*radius, *vertices, *triangles, *normals, *uvs, *tangents);

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(*vertices, *triangles, *uvs, *normals, *tangents);

	for (int i = 0; i < vertices->Num(); i++) {
		vertexColors.Add(FColor(100, 100, 100, 100));
	}

	mesh->CreateMeshSection(1, *vertices, *triangles, *normals, *uvs, vertexColors, *tangents, true);

	// With default options
	//mesh->CreateMeshSection(1, vertices, Triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);


	mesh->AttachTo(RootComponent);
	
}

// Called when the game starts or when spawned
void AMyFirstClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyFirstClass::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

