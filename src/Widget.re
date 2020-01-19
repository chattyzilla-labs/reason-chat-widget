

module WidgetLayout = {


    [@react.component] 
    
    let make = (
    ~title, 
    ~subtitle, 
    ~toggleChat, 
    ~showCloseButton, 
    ~titleAvatar, 
    ~profileAvatar,
    ~onSendMessage,
    ~senderPlaceHolder,
    ~disabledInput,
    ~autofocus,
    ~messages,
    ~typing, 
    ~toggleTyping,
    ~fullScreenMode,
    ~showChat,
    ~onToggleConversation,
    ~chatOpened,
    ~customLauncher,
    ~badge ) => {


        <div>
        {!fullScreenMode ?
          <Launcher
            chatOpened={chatOpened}
            toggle={onToggleConversation}
            badge={badge}
          />
          : React.null }
        { showChat ?
          <Conversation
          fullScreenMode={fullScreenMode}
          title={title} 
          subtitle={subtitle} 
          toggleChat={toggleChat} 
          showCloseButton={showCloseButton} 
          titleAvatar={titleAvatar}  
          profileAvatar={profileAvatar} 
          sendMessage={onSendMessage} 
          senderPlaceHolder={senderPlaceHolder} 
          disabledInput={disabledInput} 
          autofocus={autofocus} 
          messages={messages} 
          typing={typing} 
          toggleTyping={toggleTyping}
          />
          : React.null
        }

      </div>
    };
  
};

[@react.component] 

let make = (
  ~autofocus: bool, 
  ~badge: int,
  ~chatOpened: bool,
  ~customLauncher: (ReactEvent.Mouse.t => unit, React.element) =>
                        ReasonReact.reactElement,
  ~disabledInput: bool, 
  ~fullScreenMode: bool,
  ~messages: list(ReasonReact.reactElement),
  ~onSendMessage: (string, ReactEvent.Mouse.t ) => unit,
  ~onToggleConversation: ReactEvent.Mouse.t => unit,
  ~profileAvatar: option(string), 
  ~senderPlaceHolder: string,
  ~showChat: bool, 
  ~showCloseButton: bool, 
  ~subtitle: string,
  ~title: string, 
  ~titleAvatar: string,
  ~toggleChat: ReactEvent.Mouse.t => unit, 
  ~typing: bool,
  ~toggleTyping,
  ) => {

    <WidgetLayout
    onToggleConversation={onToggleConversation}
    onSendMessage={onSendMessage}
    title={title}
    typing={typing}
    toggleTyping={toggleTyping}
    toggleChat={toggleChat}
    showChat={showChat}
    messages={messages}
    titleAvatar={titleAvatar}
    subtitle={subtitle}
    senderPlaceHolder={senderPlaceHolder}
    profileAvatar={profileAvatar}
    showCloseButton={showCloseButton}
    fullScreenMode={fullScreenMode}
    badge={badge}
    autofocus={autofocus}
    customLauncher={customLauncher}
    disabledInput={disabledInput}
    chatOpened={chatOpened}
  />
    };