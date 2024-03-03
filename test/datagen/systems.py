

class BaseSystem:
    def __init__(self, initial_state):
        self.state = initial_state

    def update(self, time_step, vals):
        raise NotImplementedError("Must be implemented by subclass.")        



class sPositionNormal(BaseSystem):
    def update(self, time_step, state, vals):
        state = state +  (vals["vel"]() * time_step) + (0.5 * time_step**2 * vals["accel"])
        v = v + a * t

class sVelocityNormal(BaseSystem):
    def update(self, time_step, state, vals):
        state = state + (vals["accel"] * time_step)

class sAccelToSpeed(BaseSystem):
    def __init__(self, initial_state, speed):
        self.speed = speed
        super.__init__(inital_state)
    def update(self, time_step, state, vals):
        if(vals["vel"] > speed):
            state = 0
            

class sBattVoltRaiseToNormal(BaseSystem):
    def __init__(self, initial_state, name, normal, rate):
        self.name = name
        super.__init__(inital_state)
    def update(self, time_step, state, vals):
        if(state < normal):
            state = state + (time_step * self.rate)

