#include <eosio/eosio.hpp>
#include <eosio/transaction.hpp>

using namespace std;

class[[eosio::contract("contract")]] testTransaction : public eosio::contract
{
    public:
      using contract::contract;

    testTransaction(eosio::name receiver, eosio::name code, eosio::datastream<const char *> ds): eosio::contract(receiver, code, ds){}

    [[eosio::action]] void hi(eosio::name user);

    [[eosio::action]] void sendinline(eosio::name actor, eosio::name contract_name, eosio::name action_name, vector<char> packed_params);

    [[eosio::action]] void senddeferred(eosio::name actor, eosio::name contract_name, eosio::name action_name, vector<char> packed_params);
};
