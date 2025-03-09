// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPHelloWorld.h"

// Sets default values
ACPPHelloWorld::ACPPHelloWorld()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPHelloWorld::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this,"C++ Hello Unreal World",true,true,FColor::Blue,2.f,TEXT("None"));
}

// Called every frame
void ACPPHelloWorld::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

