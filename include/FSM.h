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

template <typename StateEnum, typename EventEnum, int MAX_STATES = 16, int MAX_TRANSITIONS = 32>
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
        // replace state action if state already present
        for (int i = 0; i < numStates; i++)
        {
            if (stateKeys[i] == state)
            {
                stateActions[i] = action;
                return;
            }
        }

        // add state action
        if (numStates < MAX_STATES)
        {
            stateKeys[numStates] = state;
            stateActions[numStates] = action;
            numStates++;
        }
    }

    /**
     * Register a transition for a event state pair and the to_state
     */
    void addTransition(StateEnum from, EventEnum event, StateEnum to)
    {
        if (numTransitions < MAX_TRANSITIONS)
        {
            transitionFrom[numTransitions] = from;
            transitionEvent[numTransitions] = event;
            transitionToState[numTransitions] = to;
            numTransitions++;
        }
    }

    template <size_t SIZE>
    void addTransition(StateEnum (&from)[SIZE], EventEnum event, StateEnum to)
    {
        for (size_t i = 0; i < SIZE; i++)
        {
            addTransition(from[i], event, to);
        }
    }

    /**
     * Calls enter() on the initial state.
     */
    void start()
    {
        StateActions* action = getAction(currentState);
        if (action) (*action).enter();
    }

    /**
     * trigers an event, checks if there is an event for the curent state, if so transitions to the to state
     */
    void processEvent(EventEnum event)
    {
        for (int i = 0; i < numTransitions; i++)
        {
            if (transitionFrom[i] == currentState && transitionEvent[i] == event)
            {
                transitionTo(transitionToState[i]);
                return;
            }
        }
    }

    /**
     * Call every loop tick. calls the update in state action
     */
    void update()
    {
        StateActions* action = getAction(currentState);
        if (action) (*action).update();
    }

    /**
     * gets the curent state
     */
    StateEnum getState() const { return currentState; }

private:
    StateEnum currentState;

    StateEnum stateKeys[MAX_STATES];
    StateActions* stateActions[MAX_STATES];
    int numStates;

    StateEnum transitionFrom[MAX_TRANSITIONS];
    EventEnum transitionEvent[MAX_TRANSITIONS];
    StateEnum transitionToState[MAX_TRANSITIONS];
    int numTransitions;

    StateActions* getAction(StateEnum state)
    {
        for (int i = 0; i < numStates; i++)
            if (stateKeys[i] == state) return stateActions[i];
        return nullptr;
    }

    void transitionTo(StateEnum newState)
    {
        if (newState == currentState) return;

        StateActions* oldAction = getAction(currentState);
        if (oldAction) (*oldAction).exit();

        currentState = newState;

        StateActions* newAction = getAction(currentState);
        if (newAction) (*newAction).enter();
    }
};