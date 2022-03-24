import java.awt.*;

/**
	Esta classe representa um placar no jogo. A classe principal do jogo (Pong)
	instancia dois objeto deste tipo, cada um responsável por gerenciar a pontuação
	de um player, quando a execução é iniciada.
*/

public class Score {
	private int points;
	private String playerId;


	/**
		Construtor da classe Score.
		@param playerId uma string que identifica o player ao qual este placar está associado.
	*/
	public Score(String playerId){
		this.playerId = playerId;
		this.points = 0;
	}


	/**
		Método de desenho do placar.
	*/
	public void draw(){
		if(playerId == "Player 1") GameLib.drawText(playerId + ": " + points, 70, GameLib.ALIGN_LEFT);
		else GameLib.drawText(playerId + ": " + points, 70, GameLib.ALIGN_RIGHT);
	}


	/**
		Método que incrementa em 1 unidade a contagem de pontos.
	*/
	public void inc(){
		points++;
	}


	/**
		Método que devolve a contagem de pontos mantida pelo placar.
		@return o valor inteiro referente ao total de pontos.
	*/
	public int getScore(){
		return points;
	}
}
