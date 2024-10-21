bool npn_transistor(bool base, bool collector) {
    if base{
        if collector{
            return true // Current flows, transistor is ON
        }
    }
    return false;// No current flows, transistor is OFF


}

bool pnp_transistor(bool base, bool emitter) {
    if
     base{

        return false
    }
    else{
        if emitter{
            return true
        }
    }
    return false; // No current flow

}
bool mosfet_nchannel(bool gate, bool source) {
    bool drain

    if source{ //source must be active
        if gate {
        drain = true

        return drain;  // Current flows between drain and source
        }
    }

    return false;
}
bool mosfet_pchannel(bool gate, bool source) {
    bool drain
    if (gate) {
        return false;  // Current flows between drain and source
    }
    return true;
}

bool NOT(int bit){
    if bit{
        npn_transistor()
    }
    else{

    }
}
