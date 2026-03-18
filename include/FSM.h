#pragma once

/**
 * Base class for per-state behavior.
 * 
 * Each class should re implement enter update and exit
 */
class StateActions
{
public:
    virtual void enter() {}
    virtual void update() {}
    virtual void exit() {}
};

template <typename StateEnum, typename EventEnum, int MAX_STATES = 8, int MAX_TRANSITIONS = 16>
class FiniteStateMachine
{
public:
    FiniteStateMachine(StateEnum initialState)
        : currentState(initialState), numStates(0), numTransitions(0) {}

    /**
     * Register a state action for a given state enum
     */
    void addStateAction(StateEnum state, StateActions* action)
    {
    }

    /**
     * Register a transition for a event state pair and the to_state
     */
    void addTransition(StateEnum from, EventEnum event, StateEnum to)
    {
    }

    /**
     * Calls enter() on the initial state.
     */
    void start()
    {
    }

    /**
     * trigers an event, checks if there is an event for the curent state, if so transitions to the to state
     */
    void processEvent(EventEnum event)
    {
    }

    /**
     * Call every loop tick. calls the update in state action
     */
    void update(float dt = 0)
    {
    }

    /**
     * gets the curent state
     */
    StateEnum getState() const { return currentState; }

private:
    StateEnum currentState;

    // State -> action map
    StateEnum    stateKeys[MAX_STATES];
    StateActions* stateActions[MAX_STATES];
    int numStates;

    // Transition table
    StateEnum  transitionFrom[MAX_TRANSITIONS];
    EventEnum  transitionEvent[MAX_TRANSITIONS];
    StateEnum  transitionTo[MAX_TRANSITIONS];
    int numTransitions;

    StateActions* getAction(StateEnum state)
    {
    }

    void transitionTo(StateEnum newState)
    {
    }
};