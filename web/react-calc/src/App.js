import React, {Component} from 'react';
import './App.scss';

import Input from './components/Input';
import ClearButton from './components/ClearButton';
import CalcButton from './components/Button';

class App extends Component  {
    constructor(props){
	super(props);

	this.state = {
	    input: "",
	    prevNum: "",
	    current: "",
	    operator: ""
	};
    }

    addToInput = val => {
	this.setState({input: this.state.input + val});
    };

    addDecimal = val => {
	// Only add decimal if one doesn't exist already
	if (this.state.input.indexOf(".") === -1) {
	    // -1 returns means searched char doesn't exist
	    this.setState({input: this.state.input + val});
	}
    };

    addZeroToInput = val => {
	// Don't want zero to be added if area is empty
	if (this.state.input !== "") {
	    this.setState({input: this.state.input + val });
	}
    };

    clearDisplay = () => {
	this.setState({input: ""});
	this.setState({operator: "plus"});
	this.setState({prevNum: "0"});
    };

    add = () => {
	this.setState({prevNum: this.state.input});
	this.setState({input: ""});
	this.setState({operator: "plus"});
    };

    subtract = () => {
	this.setState({prevNum: this.state.input});
	this.setState({input: ""});
	this.setState({operator: "minus"});
    };

    multiply = () => {
	this.setState({prevNum: this.state.input});
	this.setState({input: ""});
	this.setState({operator: "cross"});
    };

    divide = () => {
	this.setState({prevNum: this.state.input});
	this.setState({input: ""});
	this.setState({operator: "slash"});
    };

    eval = () => {
	var ans;
	if (this.state.operator === "plus") {
	    ans = parseInt(this.state.input)+parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "minus") {
	    ans = parseInt(this.state.prevNum)-parseInt(this.state.input);
	    this.setState({input: ans});
	} else if (this.state.operator === "cross") {
	    ans = parseInt(this.state.input)*parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "slash") {
	    ans = parseInt(this.state.prevNum)/parseInt(this.state.input);
	    this.setState({input: ans});
	} else{
	    this.setState({input: "Operator not supported!"});
	}
    };

    render() {
    return (
        <div className='App'>
            <div className='calcWrapper'>
            <div className='row'>
	    <Input> {this.state.input} </Input>
	    </div>
	        <div className='row'>
                    <CalcButton handleClick={() => this.addToInput(7)} >7</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(8)} >8</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(9)} >9</CalcButton>
                    <CalcButton handleClick={this.divide} >/</CalcButton>
                </div>
                <div className='row'>
                    <CalcButton handleClick={() => this.addToInput(4)} >4</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(5)} >5</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(6)} >6</CalcButton>
                    <CalcButton handleClick={this.multiply} >*</CalcButton>
                </div>
                <div className='row'>
                    <CalcButton handleClick={() => this.addToInput(1)} >1</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(2)} >2</CalcButton>
                    <CalcButton handleClick={() => this.addToInput(3)} >3</CalcButton>
                    <CalcButton handleClick={this.add} >+</CalcButton>
                </div>
                <div className='row'>
                    <CalcButton handleClick={this.addDecimal} >.</CalcButton>
                    <CalcButton handleClick={this.addZeroToInput} >0</CalcButton>
                    <CalcButton handleClick={this.eval} >=</CalcButton>
                    <CalcButton handleClick={this.subtract} >-</CalcButton>
                </div>
                <div className='row'>
	            <ClearButton handleClear={this.clearDisplay}></ClearButton>
                </div>
            </div>
        </div>
    );
    }
}

export default App;
