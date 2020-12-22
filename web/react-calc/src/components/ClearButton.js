import React, { Component } from 'react';
import { Button } from 'carbon-components-react';
import './ClearButton.scss';

class ClearButton extends Component {
    render () {
	return (
	<Button kind="danger"  className="clearButton" onClick={() => this.props.handleClear()}>
	Clear
        </Button>
	);
    }
}

export default ClearButton;
