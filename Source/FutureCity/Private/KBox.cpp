// Fill out your copyright notice in the Description page of Project Settings.

#include "FutureCity.h"
#include "KismetProceduralMeshLibrary.h"
#include "KBox.h"

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


// Sets default values
AKBox::AKBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	_mesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
	
	_sizeX = 30;
	_sizeY = 30;
	_sizeZ = 30;
	_posX = 0;
	_posY = 0;
	_posZ = 0;

	RootComponent = _mesh;
	AKBox::Draw();
}

void AKBox::sizeX(int x) { _sizeX = x; };

void AKBox::sizeY(int y) { _sizeY = y; };

void AKBox::sizeZ(int z) { _sizeZ = z; };

void AKBox::posX(int x) { _posX = x; };

void AKBox::posY(int y) { _posY = y; };

void AKBox::posZ(int z) { _posZ = z; };

void AKBox::Size(int x, int y, int z) { _sizeX = x; _sizeY = y; _sizeZ = z; };

void AKBox::Position(int x, int y, int z) { _posX = x; _posY = y; _posZ = z; };

UProceduralMeshComponent* AKBox::Mesh() { return _mesh; };

void AKBox::Draw()
{
	int i;
	FVector radius = FVector( _sizeX, _sizeY, _sizeZ);
	FVector pos = FVector( _posX, _posY, _posZ);
	TArray<FVector> *vertices = new TArray<FVector>();
	TArray<int32> *triangles = new TArray<int32>();
	TArray<FVector>* normals = new TArray<FVector>();
	TArray<FVector2D>* uvs = new TArray<FVector2D>();
	TArray<FColor> vertexColors;
	TArray<FProcMeshTangent>* tangents = new TArray<FProcMeshTangent>();

	UKismetProceduralMeshLibrary::GenerateBoxMesh(radius, *vertices, *triangles, *normals, *uvs, *tangents);

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(*vertices, *triangles, *uvs, *normals, *tangents);

	for (i = 0; i < vertices->Num(); i++) {
		vertexColors.Add(FColor(100, 100, 100, 100));
	}

	_mesh->CreateMeshSection(1, *vertices, *triangles, *normals, *uvs, vertexColors, *tangents, true);
	_mesh->SetMaterial(0,_material);

	RootComponent = _mesh;
	RootComponent->SetWorldLocation(pos);
}

// Called when the game starts or when spawned
void AKBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKBox::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

