// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "KismetProceduralMeshLibrary.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KBox.generated.h"

UCLASS(showCategories = ("Components|KBox"), ComponentWrapperClass)
class FUTURECITY_API AKBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKBox();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UProceduralMeshComponent* _mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box")
	UMaterial* _material;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _sizeX;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void sizeX(UPARAM(DisplayName = "sizeX") int x);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _sizeY;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void sizeY(UPARAM(DisplayName = "sizeY") int y);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _sizeZ;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void sizeZ(UPARAM(DisplayName = "sizeZ") int z);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _posX;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void posX(UPARAM(DisplayName = "posX") int x);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _posY;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void posY(UPARAM(DisplayName = "posY") int y);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components|KBox")
	int _posZ;

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void posZ(UPARAM(DisplayName = "posZ") int z);

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void Size(UPARAM(DisplayName = "sizeX") int x, UPARAM(DisplayName = "sizeY") int y, UPARAM(DisplayName = "sizeZ") int z);

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void Position(UPARAM(DisplayName = "posX") int x, UPARAM(DisplayName = "posY") int y, UPARAM(DisplayName = "posZ") int z);

	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	UProceduralMeshComponent* Mesh();
	
	UFUNCTION(BlueprintCallable, Category = "Components|KBox")
	void Draw();
};
