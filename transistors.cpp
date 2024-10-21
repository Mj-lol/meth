// BJT Transistors

bool npn_transistor(bool base_current, bool collector_voltage)
{
  bool emitter_output = false; // default no current flow
  if (base_current)            // base current activates the transistor
  {
    if (collector_voltage) // collector must have voltage for current to flow
    {
      emitter_output = true; // current flows, transistor ON
    }
  }
  return emitter_output; // emitter state (ON/OFF)
}

bool pnp_transistor(bool base_current, bool emitter_voltage)
{
  bool collector_output = false; // default no current flow
  if (base_current)              // base current deactivates PNP
  {
    collector_output = false; // transistor OFF
  }
  else // no base current activates the transistor
  {
    if (emitter_voltage) // emitter must have voltage for current to flow
    {
      collector_output = true; // current flows, transistor ON
    }
  }
  return collector_output; // collector state (ON/OFF)
}

// FET Transistors

bool mosfet_nchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default no current flow
  if (source_current)
  { // source must provide current
    if (gate_voltage)
    {                      // gate voltage controls the channel
      drain_output = true; // current flows from drain to source
    }
  }
  return drain_output; // drain state (ON/OFF)
}

bool mosfet_pchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default no current flow
  if (source_current)        // source must provide current
  {
    if (gate_voltage) // gate high keeps P-channel OFF
    {
      drain_output = false; // current does not flow
    }
    else // gate low activates the P-channel
    {
      drain_output = true; // current flows from source to drain
    }
  }
  return drain_output; // drain state (ON/OFF)
}
bool jfet_nchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default  no current flow
  if (source_current)        // Source must be active
  {
    if (gate_voltage) // gate high prevents current flow
    {
      drain_output = false;
    }
    else // gate low allows current flow
    {
      drain_output = true; // current flows from drain to source
    }
  }
  return drain_output; // drain state (ON/OFF)
}

bool jfet_pchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default  no current flow
  if (source_current)        // Source must be active
  {
    if (gate_voltage) // gate high allows current flow
    {
      drain_output = true; // current flows from source to drain
    }
    else // gate low prevents current flow
    {
      drain_output = false;
    }
  }
  return drain_output; // drain state (ON/OFF)
}

bool mesfet_nchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default  no current flow
  if (source_current)        // Source must be active
  {
    if (gate_voltage) // gate high prevents current flow
    {
      drain_output = false;
    }
    else // gate low allows current flow
    {
      drain_output = true; // current flows from drain to source
    }
  }
  return drain_output; // drain state (ON/OFF)
}

bool mesfet_pchannel(bool gate_voltage, bool source_current)
{
  bool drain_output = false; // default  no current flow
  if (source_current)        // Source must be active
  {
    if (gate_voltage) // P-channel MESFET allows current when gate is high
    {
      drain_output = true; // current flows from source to drain
    }
  }
  return drain_output; // drain state (ON/OFF)
}
