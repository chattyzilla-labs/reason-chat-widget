
open Styles;


   module Header = {
 

        [@react.component]
        let make = (~title: string, ~subtitle: string, ~toggleChat, ~showCloseButton: bool, ~titleAvatar=?) => {
          <div className={Header.header}>
          {switch titleAvatar {
            | Some(ta) => <img src={ta} className={Header.image} alt="profile" />
            | None => React.null
            };}
            <div className={Header.title}> {React.string(title)} </div>
            <div className={Header.closeButton} onClick={toggleChat}>
              <img className={Header.closeButtonImage} src="/assets/close-icon.png" alt="" />
            </div>
          </div>
        };
        

    };
    
    [%mui.withStyles
          "MessagesStyle"({
            rcwMessagesContainer: ReactDOMRe.Style.make( ~backgroundColor= "#fff", ~height= "50vh", ~maxHeight= "410px", ~overflowY= "scroll", ~paddingTop= "10px", ()),
            rcwAvatar: ReactDOMRe.Style.make(~width="40px", ~height="40px", ~borderRadius="100%", ~marginRight="10px", ()), 
            rcwMessage: ReactDOMRe.Style.make(~margin="10px", ~display="flex", ~wordWrap="break-word", ()),
          })
    ]; 

    module Messages = {


       

        module Loader = {

          [%mui.withStyles
          "LoaderStyle"({
            loader: ReactDOMRe.Style.make(~animationDelay="0", ~animationDuration="0.5s", ~animationName="slide-in", ~animationFillMode="forwards", ~margin="10px", ~display="none", ()), 
            loaderActive: ReactDOMRe.Style.make(~margin="10px", ~display="flex", ()),
            loaderContainer: ReactDOMRe.Style.make(~backgroundColor="$grey-2",~borderRadius="10px",~padding="15px",~maxWidth="215px",~textAlign="left", ()),
            loaderDots: ReactDOMRe.Style.make(~display="inline-block",~height="4px",~width="4px",~borderRadius="50%",~background="$grey-0",~marginRight="2px",~animation="bounce 0.5s ease infinite alternate", ()),
            dot1: ReactDOMRe.Style.make(~animationDelay="0.2s", ()),
            dot2: ReactDOMRe.Style.make(~animationDelay="0.3s", ()),
            dot3: ReactDOMRe.Style.make(~animationDelay="0.4s", ()),
            //bounce
          })
        ]; 

            //loader function
            [@react.component]
            let make = (~typing: bool) => {

                <div>
                <LoaderStyle>
                ...{classes =>{
                  let isActive = typing ? classes.loaderActive : classes.loader;
                  <div className={isActive}>
                <div className={classes.loaderContainer}>
                    <span className={classes.dot1}></span>
                    <span className={classes.dot2}></span>
                    <span className={classes.dot3}></span>
                </div>
                </div> 
                }
                
                }
                </LoaderStyle>
                </div>;
            };

        };

        module Message = {

        [%mui.withStyles
          "MessageStyle"({ 
            rcwClient: ReactDOMRe.Style.make(~marginLeft="auto", ~backgroundColor="#a3eaf7", ~borderRadius="10px", ~padding="15px", ~maxWidth="215px", ~textAlign="left", ()), 
            rcwResponse: ReactDOMRe.Style.make(~backgroundColor="#f4f7f9", ~borderRadius="10px", ~padding="15px", ~maxWidth="215px", ~textAlign="left", ()),
            rcwAvatar: ReactDOMRe.Style.make(~width="40px", ~height="40px", ~borderRadius="100%", ~marginRight="10px", ()), 
            rcwMessage: ReactDOMRe.Style.make(~margin="10px", ~display="flex", ~wordWrap="break-word", ()),
          })
        ];

            [@bs.module "../sanitizeHtml"] external sanitizedHTML: string => string = "default";

            //message function
            [@react.component]
            let make = (~message:string, ~sender) => {
                let senderstr = Printf.sprintf("rcw-%s", sender);
                <div>
               <div dangerouslySetInnerHTML={{ "__html": sanitizedHTML(message) }} />
                </div>
            
                  

            };

        };


        //Messages function
        [@react.component] 
        let make = (~profileAvatar, ~messages, ~typing) => {  
          <div>
          <MessagesStyle>
          ...{classes => 
            <div id="messages" className={classes.rcwMessagesContainer} > 
            {messages |> List.mapi((i, message) =>
              <div className={classes.rcwMessage} key={string_of_int(i)}>

              {switch (profileAvatar) {
              | Some(avatar) => <img src={avatar} className={classes.rcwAvatar} alt="profile" />
              | None => React.null
              }}
                {message}
              </div>
            ) |> Array.of_list |> ReasonReact.array}
            <Loader typing={typing} />
          </div>
            }
          </MessagesStyle>
          </div>

        };

    };

   
    module Sender = {

        open Styles.Sender;

       [@react.component] 
       let make = (~disabledInput, ~placeholder, ~autofocus, ~sendMessage, ~toggleTyping, ~typing, ~showEmoji, ~showFile, ~toggleEmoji, ~toggleFile) => {

        let text = React.useRef("");

        <div>
          {
            showFile ? 
            <div className={fileContainer} >
             <span className={iconFileMessage}><img src="/assets/file.svg" alt="" height="30" /></span>
               <span className={deleteFileMessage} onClick={(_) => toggleFile(false)}  ><img src="/assets/close.svg" alt="" height="10" title="Remove the file" /></span> 
            </div>            
               : React.null
          }
          
          <form className={userInput}>
         
           <input
             role="button"
             tabIndex=0
             onFocus={(_) => toggleTyping(true)}
             onBlur={(_) => toggleTyping(false)} 
             /* ref={ReactDOMRe.Ref.callbackDomRef(_ =>
              React.Ref.(text->setCurrent(text->current)))} */
             //onKeyDown={this.handleKey}
             //onKeyPress={this.handleKeyPress}
             //ref={ReactDOMRe.refGet(text)}
             onChange={e => React.Ref.(text->setCurrent(ReactEvent.Form.target(e)##value))} 
             placeholder="Type a message..."
             contentEditable=true
             className={userInputText}
           >
           </input>
           <div className={inputButtons}>
             <div className={userInputButton}></div>
             
             <div className={userInputButton}> 
                //{this.props.showEmoji && <EmojiIcon onEmojiPicked={this._handleEmojiPicked.bind(this)} />} 
                {Svg.emojiIcon}
             </div>
             { 

                <div className={userInputButton} onClick={(_) => toggleFile(true)}>
               {Svg.fileIcon} 
                 /* <FileIcons onChange={(file) => this._handleFileSubmit(file)} /> */
                </div>
             }
             <div className={userInputButton}  onClick={(e) => {
               sendMessage(React.Ref.current(text), e)
               React.Ref.setCurrent(text, "")
              }}>
             {Svg.sendIcon}
               // <SendIcon onClick={this._submitText.bind(this)} /> 
              </div>
           </div>
         </form>
       </div>
       } 

     };

    

    //Conversation function
    [@react.component] 
    let make = (
        ~title:string, 
        ~subtitle:string, 
        ~toggleChat, 
        ~showCloseButton:bool, 
        ~titleAvatar:string, 
        ~profileAvatar,
        ~showEmoji,
        ~showFile,
        ~sendMessage: (string, ReactEvent.Mouse.t ) => unit,
        ~senderPlaceHolder:string,
        ~disabledInput:bool,
        ~autofocus:bool,
        ~messages,
        ~typing,
        ~toggleTyping,
        ~toggleEmoji: bool => unit,
        ~toggleFile, 
        ~fullScreenMode ) => {  

        open Styles.Conversation;
 
        <div className={chatWindow} >
          <Header
            title={title}
            subtitle={subtitle}
            toggleChat={toggleChat}
            showCloseButton={showCloseButton}
            titleAvatar={titleAvatar}
          />
          <Messages
          profileAvatar={profileAvatar} messages={messages} typing={typing}
          />
          <Sender
            disabledInput={disabledInput}
            placeholder={senderPlaceHolder}
            autofocus={autofocus}
            showEmoji={showEmoji}
            showFile={showFile}
            toggleFile={toggleFile}
            toggleEmoji={toggleEmoji}
            sendMessage={sendMessage}
            toggleTyping={toggleTyping}
            typing={typing}
          />
        </div>
        } 

 


