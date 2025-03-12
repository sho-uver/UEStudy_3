// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructionScript.h"

// Sets default values
ACPPConstructionScript::ACPPConstructionScript()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Script/Engine.StaticMesh'/Game/Study/SM_SampleCube.SM_SampleCube'"),NULL,LOAD_None,NULL);
	StaticMesh->SetStaticMesh(Mesh);
	StaticMesh->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	Arrow->SetRelativeLocation(FVector(50.0f, 0, 0));
	Arrow->SetupAttachment(StaticMesh);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	PointLight->SetRelativeLocation(FVector(130.0f,0.f,0.0f));
	PointLight->SetupAttachment(StaticMesh);

}

// Called when the game starts or when spawned
void ACPPConstructionScript::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPPConstructionScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPConstructionScript::OnConstruction(const FTransform& Transform)
{
	PointLight->SetVisibility(bIsVisible);
	PointLight->SetIntensity(Intensity);
	PointLight->SetLightColor(Color);
}