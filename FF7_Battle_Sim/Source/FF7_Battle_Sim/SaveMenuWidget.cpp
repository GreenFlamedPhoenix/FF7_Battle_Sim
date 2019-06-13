// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveMenuWidget.h"
#include "WorldMenuHUD.h"

void USaveMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void USaveMenuWidget::SetWorldMenuHUD(AWorldMenuHUD* inWorldMenuHUD)
{
	WorldMenuHUD = inWorldMenuHUD;
}

/*
void USaveMenuWidget::SaveToSlot1()
{

}

void USaveMenuWidget::SaveToSlot2()
{

}

void USaveMenuWidget::SaveToSlot3()
{

}

void USaveMenuWidget::SaveToSlot4()
{

}

void USaveMenuWidget::SaveToSlot5()
{

}
*/