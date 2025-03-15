// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlBranch.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPFlowControlBranch::ACPPFlowControlBranch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPFlowControlBranch::BeginPlay()
{
	Super::BeginPlay();
	FString Message = "Hello World";
	if (IsPrintHello)
	{
		UKismetSystemLibrary::PrintString(
			this,
			Message,
			true,
			true,
			FColor::Blue,
			Duration,
			TEXT("None")
			);
	}
	else
	{
		// Add(足し算)の処理
		int32 ResultAdd = CalcVarA + CalcVarB;
		FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultAdd
			, true
			, true
			, FColor::Red
			, Duration
			, TEXT("None"));

		// Subtract(引き算)の処理
		int32 ResultSubtract = CalcVarA - CalcVarB;
		FString StrResultSubtract = FString::Printf(TEXT("%d"), ResultSubtract);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultSubtract
			, true
			, true
			, FColor::Yellow
			, Duration
			, TEXT("None"));

		// Multiply(掛け算)の処理
		int32 ResultMultiply = CalcVarA * CalcVarB;
		FString StrResultMultiply = FString::Printf(TEXT("%d"), ResultMultiply);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultMultiply
			, true
			, true
			, FColor::Green
			, Duration
			, TEXT("None"));

		// Divide(割り算)の処理
		float ResultDivide = (float)CalcVarA / (float)CalcVarB;
		FString StrResultDivide = FString::Printf(TEXT("%f"), ResultDivide);
		UKismetSystemLibrary::PrintString(
			this
			, StrResultDivide
			, true
			, true
			, FColor::Blue
			, Duration
			, TEXT("None"));
	}
	
}

// Called every frame
void ACPPFlowControlBranch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

