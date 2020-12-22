import React, {Component} from 'react';
import './App.scss';

import { Button } from 'carbon-components-react';
import Input from './components/Input';
// import CalcButton from './components/Button';
// import ClearButton from './components/ClearButton';


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

    addDecimal = () => {
	// Only add decimal if one doesn't exist already
	if (this.state.input.indexOf(".") === -1) {
	    // -1 returns means searched char doesn't exist
	    this.setState({input: this.state.input + "."});
	}
    };

    addZeroToInput = () => {
	// Don't want zero to be added if area is empty
	if (this.state.input !== "") {
	    this.setState({input: this.state.input + "0" });
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
	    ans = parseInt(this.state.input)-parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "cross") {
	    ans = parseInt(this.state.input)*parseInt(this.state.prevNum);
	    this.setState({input: ans});
	} else if (this.state.operator === "slash") {
	    ans = parseInt(this.state.input)/parseInt(this.state.prevNum);
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
                    <Button kind="tertiary" onClick={() => this.addToInput(7)} >7</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(8)} >8</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(9)} >9</Button>
                    <Button onClick={this.divide} >/</Button>
                </div>
                <div className='row'>
                    <Button kind="tertiary" onClick={() => this.addToInput(4)} >4</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(5)} >5</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(6)} >6</Button>
                    <Button onClick={this.multiply} >*</Button>
                </div>
                <div className='row'>
                    <Button kind="tertiary" onClick={() => this.addToInput(1)} >1</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(2)} >2</Button>
                    <Button kind="tertiary" onClick={() => this.addToInput(3)} >3</Button>
                    <Button onClick={this.add} >+</Button>
                </div>
                <div className='row'>
                    <Button onClick={this.addDecimal} >.</Button>
                    <Button onClick={this.addZeroToInput} >0</Button>
                    <Button onClick={this.eval} >=</Button>
                    <Button onClick={this.subtract} >-</Button>
                </div>
                <div className='row'>
	            <Button kind="danger--tertiary" onClick={this.clearDisplay}>Clear</Button>
                </div>
            </div>
        </div>
    );
    }
}

export default App;
