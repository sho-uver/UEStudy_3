// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CoreSettings.h"
#include "GameFramework/Actor.h"
#include "CPPFlowControlBranch.generated.h"

UCLASS()
class UESTUDY_3_API ACPPFlowControlBranch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPFlowControlBranch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Flow Control用の変数
	bool IsPrintHello = true;
	int32 CalcType = 0;
	int32 NumA = 1;
	int32 NumB = 2;
	int32 NumC = 15;
	bool IsBlueprint = true;
private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(255, 255, 255);

	// 計算用の変数
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

};
