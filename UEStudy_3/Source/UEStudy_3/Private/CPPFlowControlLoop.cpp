// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPFlowControlLoop.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

ACPPFlowControlLoop::ACPPFlowControlLoop()
{
	// Event Dispathcer[OnPrintHello]にCustom Event[PrintHello]をバインドする
	OnPrintHello.AddDynamic(this, &ACPPFlowControlLoop::PrintHello);
}

int32 ACPPFlowControlLoop::Sum(int32 A, int32 B)
{
	return A + B;
}

// Called when the game starts or when spawned
void ACPPFlowControlLoop::BeginPlay()
{
	Super::BeginPlay();

	SetupInput();

	if (IsPrintHello)
	{
		// Hello World!を出力する処理
		PrintHello();
	}
	else
	{
		// 計算結果を出力する処理
		PressedActionPrintCalcResult();
	}
}

void ACPPFlowControlLoop::PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration)
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

void ACPPFlowControlLoop::SetupInput()
{
	// 入力を有効にする
	EnableInput(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	// HキーのPressedとReleasedをバインドする
	InputComponent->BindKey(EKeys::H, IE_Pressed, this, &ACPPFlowControlLoop::PressedH);

	// ActionMappingsに設定したActionをバインドする
	InputComponent->BindAction("ActionPrintCalcResult", IE_Pressed, this, &ACPPFlowControlLoop::PressedActionPrintCalcResult);
}

void ACPPFlowControlLoop::PressedH()
{
	// Event Dispathcer[OnPrintHello]をコールする
	OnPrintHello.Broadcast();
}

void ACPPFlowControlLoop::PressedActionPrintCalcResult()
{
	// 計算結果を出力する処理
	PrintCalcResult(CalcTypes[TypeIndex], CalcVarA, CalcVarB, Duration);

	TypeIndex++;
	TypeIndex = TypeIndex % CalcTypes.Num();
}

void ACPPFlowControlLoop::PrintHello()
{
	
	int32 FirstIndex = 0;
	int32 LastIndex = LastIndex = Messages.Num() - 1;

	for (int32 index = FirstIndex; index <= LastIndex; index++)
	{
		if (Messages[index].Contains(TEXT("Bonjour")))
		{
			break;
		}
		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%d"), index), true, true, TextColor, Duration, TEXT("None"));
	}
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));


	/*
	for (FString Message : Messages)
	{
		if (Message.Contains(TEXT("Bonjoue")))
		{
			break;
		}
		UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration, TEXT("None"));
	}
	// CompletedをPrintStringで出力する
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
	*/

	/*
	bool NotBonjour = true;
	int32 HelloIndex = 0;
	while (NotBonjour)
	{
		if (Messages[HelloIndex].Contains(TEXT("Bonjoour")))
		{
			NotBonjour = false;
		}
		else
		{
			// Messagesの値を出力する
			UKismetSystemLibrary::PrintString(this, Messages[HelloIndex], true, true, TextColor, Duration, TEXT("None"));
		}
		HelloIndex++;
	}
	// CompletedをPrintStringで出力する
	UKismetSystemLibrary::PrintString(this, TEXT("Completed"), true, true, FColor::Cyan, Duration, TEXT("None"));
	*/

}