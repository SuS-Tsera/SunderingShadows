#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(JUNGLE);
  set_travel(FOOT_PATH);
  set_name("In a thick jungle");
  set_short("%^BOLD%^%^GREEN%^In a %^RESET%^%^GREEN%^thick%^BOLD%^"
           +" %^GREEN%^jungle");
  set_long( (:TO, "long_desc":) );
  set_items(([  ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance");
}
void init() {
   ::init();
}

void reset(){
  switch(random(10)){
  case 0:
    tell_room(TO,"A brightly coloured %^BOLD%^%^BLUE%^f%^CYAN%^i"
                +"%^BLUE%^sh%^RED%^e%^BLUE%^r-b%^CYAN%^i%^GREEN%^r"
                +"%^BLUE%^d%^RESET%^ swoops down into the water in a"
                +" streamlined dive, before surfacing again with a"
                +" %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^WHITE%^lver"
                +" f%^RESET%^i%^BOLD%^%^WHITE%^sh%^RESET%^ in its beak");
    break;
  case 1:
    tell_room(TO,"A small family of %^ORANGE%^warthogs%^RESET%^ snuffles"
                +" its way down to drink from the water at the far side"
                +" of the pond.");
    break;
  case 2:
    tell_room(TO,"%^CYAN%^A %^RESET%^silent r%^BOLD%^%^WHITE%^i"
                +"%^RESET%^pple %^CYAN%^disturbs the surface of the"
                +" water");
    break;
  case 3:
    tell_room(TO,"A huge fish surfaces, gulping at a %^BOLD%^%^GRREEN%^"
               +"dr%^CYAN%^a%^GREEN%^g%^BLUE%^o%^GREEN%^nfly%^RESET%^"
               +" hovering over the surface of the water, before rolling"
               +" back into the darkness below");
    break;
  case 4: 
    tell_room(TO,"You notice a %^ORANGE%^huge log%^RESET%^ drifting"
                 +" across the water hole");
    add_item("log","A %^ORANGE%^huge log%^RESET%^ drifts slowly on"
                      +" the surface of the %^CYAN%^watering hole");
    call_out( "remove_log", 7);
    break;
  }
}



int remove_log(string str){
  tell_room(TO,"The %^ORANGE%^huge log%^RESET%^ drifts slowly out of view"
                 );
  remove_item("log");
}

string long_desc(){
return "%^GREEN%^A few distinct animal trails converge here at a natural"
      +" %^CYAN%^watering hole%^GREEN%^. The %^CYAN%^water%^GREEN%^ looks"
      +" very still, covered with a %^BOLD%^%^GREEN%^gr%^RESET%^%^GREEN"
      +"%^ee%^BOLD%^%^GREEN%^n f%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^lm"
      +"%^RESET%^%^GREEN%^. Some %^BOLD%^%^MAGENTA%^p%^RED%^a"
      +"%^MAGENTA%^rr%^YELLOW%^o%^MAGENTA%^ts%^RESET%^%^GREEN%^ squawk"
      +" and play in the foliage overhead. Various animals arrive from"
      +" time to time to drink from the %^CYAN%^water%^GREEN%^.\n";
}
