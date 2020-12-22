import React, { Component } from 'react';
import { Tile } from 'carbon-components-react';
import './Input.scss';

class Input extends Component {
    render() {
        return (
		<Tile className="input">
		{this.props.children}
		</Tile>
        );
    }
}
export default Input;
