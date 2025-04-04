// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCalcInfo.h"
#include "GameFramework/Actor.h"
#include "CPPCalcType.h"
#include "CPPStructure.generated.h"

UCLASS()
class UESTUDY_3_API ACPPStructure : public AActor
{
	GENERATED_BODY()

public:
	ACPPStructure();

	// Event Dispatcher[OnPrintHello]
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
	FPrintHelloDelegate OnPrintHello;

	// Custom Event[PrintHello] 
	UFUNCTION()
	void PrintHello();

	int32 Sum(int32 A, int32 B);

	// Action Mappingsに設定したActionを処理する関数
	void PressedActionPrintCalcResult();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<FString> Messages = { TEXT("C++ Hello World!"), TEXT("你好 世界!"), TEXT("Bonjour le monde!"), TEXT("Hallo Welt!"), TEXT("こんにちは世界!") };

	// 計算結果を出力する関数
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FColor(255, 255, 255);

	// 計算用の変数
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control用の変数
	bool IsPrintHello = false;
	int32 TypeIndex = 0;
	TArray<ECPPCalcType> CalcTypes = { ECPPCalcType::Add, ECPPCalcType::Subtract, ECPPCalcType::Multiply, ECPPCalcType::Divide };

	// Input設定
	void SetupInput();

	// Input Eventを処理する関数
	void PressedH();

private:
	void PrintCalcResultArgStructure(const FCPPCalcInfo& CalcInfo, const float PrintDuration);

	FCPPCalcInfo CalcInfo = {ECPPCalcType::Add, 7, 3};
	TArray<FCPPCalcInfo> CalcInfos = {
		{ ECPPCalcType::Add, 7, 3 },
		{ ECPPCalcType::Subtract, 7, 3 },
		{ ECPPCalcType::Multiply, 7, 3 },
		{ ECPPCalcType::Divide, 7, 3 }
	};

};
