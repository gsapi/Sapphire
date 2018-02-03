#include "../ScriptObject.h"

// Quest Script: ManWil001_00594
// Quest Name: Coming to Ul'dah
// Quest ID: 66130
// Start NPC: 1003987
// End NPC: 1003988

class ManWil001 : public EventScript
{
private:
   static constexpr auto SEQ_0 = 0;
   static constexpr auto SEQ_FINISH = 255;

   static constexpr auto ACTOR0 = 1003987;
   static constexpr auto ACTOR1 = 1003988;
   static constexpr auto ACTOR20 = 1001285;
   static constexpr auto CUT_EVENT = 188;
   static constexpr auto EOBJECT0 = 2001681;
   static constexpr auto EOBJECT1 = 2001682;
   static constexpr auto EOBJECT2 = 2001683;
   static constexpr auto EOBJECT3 = 2001706;
   static constexpr auto EVENT_ACTION_SEARCH = 1;
   static constexpr auto OPENING_EVENT_HANDLER = 1245187;

   void Scene00000( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         if( param2 == 1 )
         {
            player.setOpeningSequence( 2 );
            Scene00001( player );
         }
      };

      player.eventPlay( getId(), 0, HIDE_HOTBAR, 0, 0, callback );
   }

   void Scene00001( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00002( player );
      };

      player.eventPlay( getId(), 1, 0xF8482EFB, 0, 0, callback );
   }

   void Scene00002( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         player.updateQuest( getId(), SEQ_FINISH );
         player.eventPlay( OPENING_EVENT_HANDLER, 0x1E, HIDE_HOTBAR | NO_DEFAULT_CAMERA, 0, 0 );
      };

      player.eventPlay( getId(), 2, NONE, 0, 0, callback );
   }

   void Scene00003( Entity::Player& player )
   {
      player.eventPlay( getId(), 3, 0, 0, 0 );
   }

   void Scene00004( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         Scene00005( player );
      };

      player.eventPlay( getId(), 4, 0x2c02, 0, 0, callback );
   }

   void Scene00005( Entity::Player& player )
   {
      auto callback = [ this ]( Entity::Player& player, uint32_t eventId, uint16_t param1, uint16_t param2, uint16_t param3 )
      {
         if( param2 == 1 )
         {
            if( player.giveQuestRewards( getId(), 0 ) )
               player.finishQuest( getId() );
         }
      };

      player.eventPlay( getId(), 5, INVIS_OTHER_PC, 0, 0, callback );
   }

   void Scene00006( Entity::Player& player )
   {
      player.eventPlay( getId(), 6, 0, 0, 0 );
   }

   void Scene00007( Entity::Player& player )
   {
      player.eventPlay( getId(), 7, 0, 0, 0 );
   }

   void Scene00008( Entity::Player& player )
   {
      player.eventPlay( getId(), 8, 0, 0, 0 );
   }

   void Scene00009( Entity::Player& player )
   {
      player.eventPlay( getId(), 9, 0, 0, 0 );
   }

   void Scene00010( Entity::Player& player )
   {
      player.eventPlay( getId(), 10, 0, 0, 0 );
   }

   void Scene00011( Entity::Player& player )
   {
      player.eventPlay( getId(), 11, 0, 0, 0 );
   }

   void Scene00012( Entity::Player& player )
   {
      player.eventPlay( getId(), 12, 0, 0, 0 );
   }

   void Scene00013( Entity::Player& player )
   {
      player.eventPlay( getId(), 13, 0, 0, 0 );
   }


public:
   ManWil001() : EventScript( 66130 ) {}

   void onTalk( uint32_t eventId, Entity::Player& player, uint64_t actorId ) override
   {
      auto actor = Event::mapEventActorToRealActor( static_cast< uint32_t >( actorId ) );

      if( actor == ACTOR0 )
         Scene00000( player );
      else if( actor == ACTOR1 )
         Scene00004( player );
   }
};