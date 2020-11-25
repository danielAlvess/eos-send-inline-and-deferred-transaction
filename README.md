# eos smart contract to send action as inline or deferred

### complie contract and deploy contract:

```bash
eosio-cpp -abigen -I include -contract contract -o contract.wasm contract.cpp
cleos -u https://testnet.canfoundation.io set contract testtransact . contract.wasm contract.abi -p testtransact@active
```
### pack action data parameter:

pack action data you want to execute as inline or deferred by command:

```bash
cleos convert pack_action_data eosio.token transfer '["daniel111111", "daniel111114", "0.0001 CAT", "test"]'
1042082144e5a6494042082144e5a649010000000000000004434154000000000474657374
```

### delegate eosio.code permission for testtransact contract

```bash
cleos set account permission daniel111111 active '{"threshold": 1,"keys": [{"key": "EOS6yfoREUrCWa1MZkjnfhLyG2cBk9spkayth6NKPBCmpLkzEK7NG","weight": 1}],"accounts": [{"permission":{"actor":"testtransact","permission":"eosio.code"},"weight":1}]}' owner -p daniel111111
```

### send action as inline

```bash
cleos push action testtransact sendinline '["daniel111111", "eosio.token", "transfer", "1042082144e5a6494042082144e5a649010000000000000004434154000000000474657374"]' -p daniel111111
```


### send action as deferred

```bash
cleos push action testtransact senddeferred '["daniel111111", "eosio.token", "transfer", "1042082144e5a6494042082144e5a649010000000000000004434154000000000474657374"]' -p daniel111111
```
