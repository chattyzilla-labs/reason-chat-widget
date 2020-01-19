
module Badge = {

    [@react.component]
    let make = (~badge: int, ~chatOpened) => {
      
        {badge > 0 && !chatOpened ? <div className={Styles.Badge.messageCount}>{React.string(string_of_int(badge))}</div> : React.null}
      
    }
};

[@react.component]
let make = (~badge: int, ~chatOpened: bool, ~toggle) => {

  open Styles.Launcher;

    let isOpened = chatOpened ? button ++ " " ++ buttonOpened : button;
    let openIcon = chatOpened ? icon ++ " " ++ openIcon ++ " " ++ openIconWhenOpened : icon ++ " " ++ openIcon;
    let closeIcon = chatOpened ? icon ++ " " ++ closeIcon ++ " " ++ closeIconWhenOpened : icon ++ " " ++ closeIcon;

    <div className={isOpened} onClick={toggle}>
    <Badge badge={badge} chatOpened={chatOpened} />
      <img src="/assets/chat-icon.svg"  className={openIcon} alt="" />
      <img src="/assets/close-icon.png" className={closeIcon} alt="" /> 
    </div>
   

   
  }




