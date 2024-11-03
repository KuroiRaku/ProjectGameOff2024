#include "BaseAIController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"


// Sets default values
ABaseAIController::ABaseAIController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComponent");
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>("BlackboardComponent");

}

// Called every frame
void ABaseAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(IsValid(BehaviorTree))
	{
		RunBehaviorTree(BehaviorTree);
	}
}

// Called when the game starts or when spawned
void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();
}


