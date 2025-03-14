// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
# include "kismet/kismetStringLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

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

	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcvarA,CalcvarB);
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	UKismetSystemLibrary::PrintString(
		this,
		StrResultAdd,
		true,
		true,
		FColor::Red,
		Duration,
		TEXT("None"));

}
