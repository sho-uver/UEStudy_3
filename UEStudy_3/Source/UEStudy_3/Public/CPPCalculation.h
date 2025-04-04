#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPCalculation.generated.h"
#ifdef UEStudy_3_EXPORTS
	#define UEStudy_3_API __attribute__ ((visibility("default")))
#else
	#define UEStudy_3_API
#endif

UCLASS()
class UEStudy_3_API ACPPCalculation : public AActor
{
	GENERATED_BODY()

	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	private:
	// PrintString関数のDurationに設定する変数
	const float Duration = 10.0f;

	// PrintString関数のTextColorに設定する変数
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

	int32 CalcvarA = 7;
	int32 CalcvarB = 3;
};
