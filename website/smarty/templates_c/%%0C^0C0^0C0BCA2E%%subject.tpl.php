<?php /* Smarty version 2.6.17, created on 2008-05-08 14:01:19
         compiled from subject.tpl */ ?>
<?php require_once(SMARTY_CORE_DIR . 'core.load_plugins.php');
smarty_core_load_plugins(array('plugins' => array(array('modifier', 'date_format', 'subject.tpl', 5, false),)), $this); ?>
<div id="primarycontent">
	<div class="post">
		<div class="header">
			<h3>ZAPPY Bibicy:</h3>
			<div id="date"><?php echo ((is_array($_tmp=time())) ? $this->_run_mod_handler('date_format', true, $_tmp, "%A %B %e, %Y") : smarty_modifier_date_format($_tmp, "%A %B %e, %Y")); ?>
</div>
		</div>
		<div class="content">
			<center><h4><strong>Jeu en r�seau en temps r�el avec un serveur et de multiples clients.</strong></h4></center>
			<br />
			<img src="images/zappy.png" class="picA floatleft" alt="" /><br />
			<h4><strong><u>But du projet :</u></strong></h4> 
			D�velopper en C un serveur de jeu zappy et un client graphique en C ou Perl.
		</div>
		<br /><br />
		<div class="content">
			<h4><u><strong>Principe :</strong></u></h4>
			Le jeu consiste � g�rer un univers et ses habitants. Ce monde, nomm� Trantor, est g�ographiquement constitu� de plaines et ne comprend aucun autre relief.
			<br /><br />
			Le plateau de jeu repr�sente la totalit� de la surface de ce monde, comme un planisph�re. Des ressources alimentaires et mini�res sont g�n�r�es al�atoirement sur le terrain.
			<br /><br />
			Le Trantorien est pacifique. Il n'est ni violent, ni agressif. Il d�ambule gaiement en qu�te de pierres et s'alimente au passage. Il croise sans difficult� ses semblables sur une m�me unit� de terrain et voit aussi loin que ses capacit�s visuelles le lui permettent.
			<br /><br />
			C'est un �tre immat�riel, flou, qui occupe toute la case dans laquelle il se trouve. Il est impossible de distinguer son orientation lorsqu'on le croise. La nourriture qu'il ramasse lui permet de vivre pendant un certain laps de temps.
			<br /><br />
			L'objectif des joueurs est de s'�lever dans la hi�rarchie trantorienne. Cette "augmentation", qui permet d'accro�tre ses capacit�s physiques et mentales, doit �tre effectu�e selon un rite particulier. Il faut en effet r�unir sur la m�me unit� de terrain:
			<br /><br />
			* Une combinaison de pierres,<br />
			* Un certain nombre de joueurs de m�me niveau.
			<br /><br />
			Un joueur d�bute l'incantation et lance ainsi le processus d'�l�vation. Il n'est pas n�cessaire que les participants soient de la m�me �quipe. Seul leur niveau importe. Tous les joueurs du groupe r�alisant l'incantation atteignent le niveau sup�rieur.
			<br /><br />
			Pour compliquer la t�che de l'IA, le champ de vision des joueurs est limit�. A chaque �l�vation, la vision augmente d'une unit� de mesure en avant et d'une de chaque c�t� de la nouvelle rang�e.
			<br /><br />
			Un Trantorien a �galement moyen de d�tecter la pr�sence de ses cong�n�res en �mettant une onde-radar lui indiquant la direction � prendre pour les rejoindre.
			<br /><br />
			Le jeu se joue par �quipe. L'�quipe gagnante est celle dont six joueurs auront atteint l'�l�vation maximale.
		</div>			
	</div>
</div>