

[@bs.send] external charCodeAt: string => unit = "charCodeAt";
module Chat = {

type action =
| ToggleConvo
| SendMessage(string)
| ToggleIsTyping(bool)
| ToggleEmoji(bool)
| ToggleFile(bool)

type state = {
_open: bool,
unread:int,
messages: list(ReasonReact.reactElement),
typing: bool,
showEmoji: bool,
showFile: bool
};

let deco_UTF8: string => string = [%raw
      (str) => "return decodeURIComponent(escape(str))"
];
let winking_face = "😉";
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(
    (state, action) =>
      switch (action) {
      | ToggleConvo => {...state, _open: state._open ? false : true, unread: 0}
      | SendMessage(str) => {...state, messages: List.append(state.messages, [ <div style={ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ())}>{React.string(str)}</div>])}
      | ToggleIsTyping(bool) => {...state, typing: bool}
      | ToggleEmoji(bool) => {...state, showEmoji: bool}
      | ToggleFile(bool) => {...state, showFile: bool}
      },
    {_open: true, typing: false, unread: 4, showEmoji:false, showFile: false, 
      messages:[<div>{React.string("hey, what's up man?")}</div>,
                <div>{React.string("nothing much, you?")}</div>  ]}
  );

  let a = (_, child) => <div>{child}</div>;
  let b = "/assets/avatar.svg"; 
  
<Widget    
onToggleConversation={(_) => dispatch(ToggleConvo)}
onSendMessage={(str, e) => { 
  print_endline(str)
    let _ = ReactEvent.Mouse.preventDefault(e)
    dispatch(SendMessage(str))}}
toggleTyping={(bool) => dispatch(ToggleIsTyping(bool))}
title="Jeff Hoffman"
typing={state.typing}
toggleChat={(_) => dispatch(ToggleConvo)}
toggleEmoji={(bool) => dispatch(ToggleEmoji(bool))}
toggleFile={(bool) => dispatch(ToggleFile(bool))}
showChat={state._open}
messages={state.messages}
titleAvatar=b
showEmoji={state.showEmoji}
showFile={state.showFile}
subtitle=""
senderPlaceHolder="Write a reply..."
profileAvatar={Some(b)}
showCloseButton=false
fullScreenMode=false
badge={state.unread}
autofocus=true
customLauncher={a}
disabledInput=false
chatOpened={state._open}/> 
};



};

<Chat/> -> ReactDOMRe.renderToElementWithId("index2")


//ReactDOMRe.renderToElementWithId(<Component2 greeting="Another Greeting" />, "index2");
