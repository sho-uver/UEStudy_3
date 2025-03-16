// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlSwitch.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPFlowControlSwitch::ACPPFlowControlSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPFlowControlSwitch::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	if (IsPrintHello)
	{
		// PrintStringノードと同じ処理
		// UKismetSystemLibraryクラスのPrintString関数を呼び出す
		UKismetSystemLibrary::PrintString(
			this
			, Message
			, true
			, true
			, TextColor// Textのカラー情報に変数TextColorを設定
			, Duration
			, TEXT("None"));
	}
	else
	{
		switch(CalcType)
		{
		case 0:
			{
				int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
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
		case 1:
			{
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
		case 2:
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
		case 3:
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
			}
		default:
			{
				UKismetSystemLibrary::PrintString(
					this,
					TEXT("CalcTypeの値が不正です。"),
					true,
					true,
					FColor::Red,
					Duration,
					TEXT("None"));
				break;
			}
			
			
		}

	};
	
}


