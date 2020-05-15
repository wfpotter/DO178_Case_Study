myDictionaryObj = ...
Simulink.data.dictionary.open('HeliSystemDD.sldd');
dConfigSectObj = getSection(myDictionaryObj,'Configurations');
refConfigSetObj = dConfigSectObj.getEntry('Config');
refConfigSet = refConfigSetObj.getValue();
set_param(refConfigSet, 'HardwareBoard', 'ZedBoard');
set_param(refConfigSet, 'HardwareBoardFeatureSet', 'EmbeddedCoderHSP');
refConfigSetObj.setValue(refConfigSet);
myDictionaryObj.saveChanges();