// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
ACPPVariable::ACPPVariable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();
	FString Message = "C++daze";
	Duration = 12.0f;
	UKismetSystemLibrary::PrintString(
		this,
		UKismetStringLibrary::Conv_DoubleToString(Duration),
		true,
		true,
		FColor::Cyan,
		Duration,
		TEXT("None"));
}

// Called every frame
void ACPPVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

