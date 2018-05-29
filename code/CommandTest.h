#pragma once
#include "CommandPattern.h"

void CommandTest() {
	Light light;
	Door door;
	Command* lighton = new LightOnCommand(&light);
	Command* lightoff = new LightOffCommand(&light);
	Command* dooropen = new DoorOpenCommand(&door);
	Command* doorclose = new DoorCloseCommand(&door);

	RemoteControl control;
	control.onButtonPushed();
	control.offButtonPushed();

	control.setCommand(lighton, lightoff);
	control.onButtonPushed();
	control.offButtonPushed();

	control.setCommand(dooropen, doorclose);
	control.onButtonPushed();
	control.offButtonPushed();
}