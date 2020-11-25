#include "contract.hpp"

using namespace eosio;

void testTransaction::hi(name user){
    print( "hello, ", user);
}

void testTransaction::sendinline(eosio::name actor, eosio::name contract_name, eosio::name action_name, vector<char> packed_params){
  require_auth(actor);
  // eosio::action(
  //   permission_level{actor, "active"_n},
  //   contract_name,
  //   action_name,
  //   packed_params
  // ).send();

  action sending_action;
  sending_action.authorization.push_back(permission_level{actor, "active"_n});
  sending_action.account = contract_name;
  sending_action.name = action_name;
  sending_action.data = packed_params;
  sending_action.send();
}

void testTransaction::senddeferred(eosio::name actor, eosio::name contract, eosio::name action_name, vector<char> packed_params){
  require_auth(actor);
  eosio::transaction t{};
  t.actions.emplace_back(
    permission_level(actor, "active"_n),
    contract,
    action_name,
    packed_params
  );

  t.actions[0].data = packed_params;

  t.delay_sec = 1;
  t.send(1, actor);
}

