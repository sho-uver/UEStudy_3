// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPInputEvent.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

int32 ACPPInputEvent::Sum(int32 A, int32 B)
{
	return A + B;
}
// Called when the game starts or when spawned
void ACPPInputEvent::BeginPlay()
{
	Super::BeginPlay();
	SetupInput();

	if (IsPrintHello)
	{
		// PrintStringノードと同じ処理
		// UKismetSystemLibraryクラスのPrintString関数を呼び出す
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
	}
	else
	{
		// 計算結果を出力する処理
		PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
	}
}

void ACPPInputEvent::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
{
	switch (Type)
	{
	case ECPPCalcType::Add:
		{
			// Add(足し算)の処理
			int32 ResultAdd = Sum(CalcVarA, CalcVarB);
			FString StrResultAdd = FString::Printf(TEXT("%d"), ResultAdd);
			UKismetSystemLibrary::PrintString(
				this
				, StrResultAdd
				, true
				, true
				, FColor::Red
				, Duration
				, TEXT("None"));
			break;
		}
	case ECPPCalcType::Subtract:
		{
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
			break;
		}
	case ECPPCalcType::Multiply:
		{
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
			break;
		}
	case ECPPCalcType::Divide:
		{
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
			break;
		}
	}
	
}
void ACPPInputEvent::SetupInput()
{
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	InputComponent->BindKey(EKeys::H,IE_Pressed,this, &ACPPInputEvent::PressedH);
	InputComponent->BindAction("ActionPrintCalcResult",IE_Pressed,this, &ACPPInputEvent::PressedActionPrintCalcResult);
		
}

void ACPPInputEvent::PressedH()
{
	UKismetSystemLibrary::PrintString(this,Message,true,true,TextColor,Duration,TEXT("None"));
}
	
void ACPPInputEvent::ReleasedH()
{
	// 計算結果を出力する処理
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}

void ACPPInputEvent::PressedActionPrintCalcResult()
{
	PrintCalcResult(CalcType, CalcVarA, CalcVarB, Duration);
}




