import React from  "react";

const App = props => {
  if (props.show) {
    return (
      <div className="App">
        {"Here's the message from the owner: " +
          (props.message === undefined ? "3" : props.message.text)}
      </div>
    );
  } else {
    return null;
  }
};

export default App;