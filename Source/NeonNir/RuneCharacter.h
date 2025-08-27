#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RuneCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class NEONNIR_API ARuneCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    ARuneCharacter();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    USpringArmComponent* CameraBoom;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess="true"))
    UCameraComponent* FollowCamera;

    UPROPERTY(EditAnywhere, Category="Movement")
    float WalkSpeed = 600.f;

    UPROPERTY(EditAnywhere, Category="Movement")
    float SprintSpeed = 900.f;

    bool bIsSprinting;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void Turn(float Value);
    void LookUp(float Value);
    void StartSprint();
    void StopSprint();

    void CastRune();
};

